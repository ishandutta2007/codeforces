#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,lt,f[101][101],ans,k[1000001],a[1000001];
class bigint {
	protected:
		static const int __BASE=1000000000;
		static const int __BASE_DIGITS=9;
		vector <int> a;
		int sign;
		static pair<bigint,bigint> divmod(const bigint &a1,const bigint &b1) {
			int norm=__BASE/(b1.a.back()+1);
			bigint a=a1.abs()*norm;
			bigint b=b1.abs()*norm;
			bigint q,r;
			q.a.resize(a.a.size());
			for (int i=a.a.size()-1;i>=0;i--) {
				r*=__BASE;r+=a.a[i];
				int s1=r.a.size()<=b.a.size()?0:r.a[b.a.size()];
				int s2=r.a.size()<=b.a.size()-1?0:r.a[b.a.size()-1];
				int d=((long long) __BASE*s1+s2)/b.a.back();
				r-=b*d; while (r<0) r+=b,--d;
				q.a[i]=d;
			}
			q.sign=a1.sign*b1.sign;
			r.sign=a1.sign;
			q.trim(); r.trim();
			return make_pair(q,r/norm);
		}
		void trim() {
			while (!a.empty() && !a.back()) a.pop_back();
			if (a.empty()) sign=1;
		}
		static vector<int> convert_base(const vector<int> &a,int old_digits,int new_digits) {
			vector<long long> p(max(old_digits,new_digits)+1);
			p[0]=1;
			for (int i=1;i<(int) p.size();i++)
				p[i]=p[i-1]*10;
			vector<int> res;
			long long cur=0;
			int cur_digits=0;
			for (int i=0;i<(int) a.size();i++) {
				cur+=a[i]*p[cur_digits];
				cur_digits+=old_digits;
				while (cur_digits>=new_digits) {
					res.push_back(int(cur%p[new_digits]));
					cur /= p[new_digits];
					cur_digits-=new_digits;
				}
			}
			res.push_back((int) cur);
			while (!res.empty() && !res.back())
				res.pop_back();
			return res;
		}
		static vector<long long> karatsubaMultiply(const vector<long long> &a,const vector<long long> &b) {
			int n=a.size();
			vector<long long> res(n+n);
			if (n<=32) {
				for (int i=0;i<n;i++) for (int j=0;j<n;j++)
					res[i+j]+=a[i]*b[j];
				return res;
			}
			int k=n>>1;
			vector<long long> a1(a.begin(),a.begin()+k);
			vector<long long> a2(a.begin()+k,a.end());
			vector<long long> b1(b.begin(),b.begin()+k);
			vector<long long> b2(b.begin()+k,b.end());
			vector<long long> a1b1=karatsubaMultiply(a1,b1);
			vector<long long> a2b2=karatsubaMultiply(a2,b2);
			for (int i=0;i<k;i++) a2[i]+=a1[i];
			for (int i=0;i<k;i++) b2[i]+=b1[i];
			vector<long long> r=karatsubaMultiply(a2,b2);
			for (int i=0;i<(int) a1b1.size();i++) r[i]-=a1b1[i];
			for (int i=0;i<(int) a2b2.size();i++) r[i]-=a2b2[i];
			for (int i=0;i<(int) r.size();i++) res[i+k]+=r[i];
			for (int i=0;i<(int) a1b1.size();i++) res[i]+=a1b1[i];
			for (int i=0;i<(int) a2b2.size();i++) res[i+n]+=a2b2[i];
			return res;
		}
	public:
		inline int size() {
			if (a.empty()) return 0;
			int ans=(a.size()-1)*__BASE_DIGITS;
			int ca=a.back();
			while (ca) ans++,ca/=10;
			return ans;
		}
		bigint operator^(const bigint &v) {
			bigint ans=1,a=*this,b=v;
			while (!b.isZero()) {
				if (b%2) ans*=a;
				a*=a,b/=2;
			}
			return ans;
		}
		inline string to_string() {
			stringstream ss;
			ss<<*this;
			string s;
			ss>>s;
			return s;
		}
		inline int sumof() {
			string s=to_string();
			int ans=0;
			for (auto c:s) ans+=c-'0';
			return ans;
		}
		bigint():sign(1) { }
		bigint(long long v) { *this=v; }
		bigint(const string &s) { from_string(s); }
		bigint& operator=(const bigint &v) { sign=v.sign;a=v.a;return *this; }
		bigint& operator=(long long v) {
			sign=1; a.clear();
			if (v<0) sign=-1,v=-v;
			for (;v>0;v=v/__BASE)
				a.push_back(v%__BASE);
			return *this;
		}
		bigint operator+(const bigint &v) const {
			if (sign==v.sign) {
				bigint res=v;
				for (int i=0,carry=0;i<(int) max(a.size(),v.a.size()) || carry;++i) {
					if (i==(int) res.a.size()) res.a.push_back(0);
					res.a[i]+=carry+(i<(int) a.size()?a[i]:0);
					carry=res.a[i]>=__BASE;
					if (carry) res.a[i]-=__BASE;
				}
				return res;
			}
			return *this-(-v);
		}
		bigint operator-(const bigint &v) const {
			if (sign==v.sign) {
				if (abs()>=v.abs()) {
					bigint res=*this;
					for (int i=0,carry=0;i<(int) v.a.size() || carry;++i) {
						res.a[i]-=carry+(i<(int) v.a.size()?v.a[i]:0);
						carry=res.a[i]<0;
						if (carry) res.a[i]+=__BASE;
					}
					res.trim();
					return res;
				}
				return -(v-*this);
			}
			return *this+(-v);
		}
		bigint operator*(const bigint &v) const {
			vector<int> a6=convert_base(this->a,__BASE_DIGITS,6);
			vector<int> b6=convert_base(v.a,__BASE_DIGITS,6);
			vector<long long> a(a6.begin(),a6.end());
			vector<long long> b(b6.begin(),b6.end());
			while (a.size()<b.size())
				a.push_back(0);
			while (b.size()<a.size())
				b.push_back(0);
			while (a.size() & (a.size()-1))
				a.push_back(0),b.push_back(0);
			vector<long long> c=karatsubaMultiply(a,b);
			bigint res;
			res.sign=sign*v.sign;
			for (int i=0,carry=0;i<(int) c.size();i++) {
				long long cur=c[i]+carry;
				res.a.push_back((int) (cur%1000000));
				carry=(int) (cur/1000000);
			}
			res.a=convert_base(res.a,6,__BASE_DIGITS);
			res.trim();
			return res;
		}
		bigint& operator*=(int v) {
			if (v<0) sign=-sign,v=-v;
			for (int i=0,carry=0;i<(int) a.size() || carry;++i) {
				if (i==(int) a.size()) a.push_back(0);
				long long cur=a[i]*(long long) v+carry;
				carry=(int) (cur/__BASE);
				a[i]=(int) (cur%__BASE);
			}
			trim();
			return *this;
		}
		bigint operator*(int v) const {
			bigint res=*this;
			res*=v;
			return res;
		}
		bigint& operator*=(long long v) {
			if (v<0) sign=-sign,v=-v;
			for (int i=0,carry=0;i<(int) a.size() || carry;++i) {
				if (i==(int) a.size()) a.push_back(0);
				long long cur=a[i]*(long long) v+carry;
				carry=(int) (cur/__BASE);
				a[i]=(int) (cur%__BASE);
			}
			trim();
			return *this;
		}
		bigint operator*(long long v) const {
			bigint res=*this;
			res*=v;
			return res;
		}
		bigint operator/(const bigint &v) const {
			return divmod(*this,v).first;
		}
		bigint operator%(const bigint &v) const {
			return divmod(*this,v).second;
		}
		bigint& operator/=(int v) {
			if (v<0) sign=-sign,v=-v;
			for (int i=(int) a.size()-1,rem=0;i>=0;--i) {
				long long cur=a[i]+rem*(long long) __BASE;
				a[i]=(int) (cur/v);
				rem=(int) (cur%v);
			}
			trim();
			return *this;
		}
		bigint operator/(int v) const {
			bigint res=*this;
			res/=v;
			return res;
		}
		int operator%(int v) const {
			if (v<0) v=-v;
			int m=0;
			for (int i=a.size()-1;i>=0;--i)
				m=(a[i]+m*(long long) __BASE)%v;
			return m*sign;
		}
		bigint& operator+=(const bigint &v) {
			*this=*this+v;
			return *this;
		}
		bigint& operator-=(const bigint &v) {
			*this=*this-v;
			return *this;
		}
		bigint& operator*=(const bigint &v) {
			*this=*this*v;
			return *this;
		}
		bigint& operator/=(const bigint &v) {
			*this=*this/v;
			return *this;
		}
		bigint& operator%=(const bigint &v) {
			*this=*this%v;
			return *this;
		}
		bool operator<(const bigint &v) const {
			if (sign != v.sign)
				return sign<v.sign;
			if (a.size() != v.a.size())
				return a.size()*sign<v.a.size()*v.sign;
			for (int i=a.size()-1;i>=0;i--)
				if (a[i] != v.a[i])
					return a[i]*sign<v.a[i]*sign;
			return false;
		}
		bool operator>(const bigint &v) const {
			return v<*this;
		}
		bool operator<=(const bigint &v) const {
			return !(v<*this);
		}
		bool operator>=(const bigint &v) const {
			return !(*this<v);
		}
		bool operator==(const bigint &v) const {
			return !(*this<v) && !(v<*this);
		}
		bool operator!=(const bigint &v) const {
			return *this<v || v<*this;
		}
		bool isZero() const {
			return a.empty() || (a.size()==1 && !a[0]);
		}
		bigint operator-() const {
			bigint res=*this;
			res.sign=-sign;
			return res;
		}
		bigint abs() const {
			bigint res=*this;
			res.sign*=res.sign;
			return res;
		}
		bigint operator--() {
			return *this-=1;
		}
		bigint operator++() {
			return *this+=1;
		}
		unsigned long long to_ullong() const {
			if (a.size()>64) throw "BIGINT TOO LARGE TO A LONGINT";
			unsigned long long res=0;
			for (int i=a.size()-1;i>=0;i--)
				res=res*__BASE+a[i];
			return res*sign;
		}
		static bigint gcd(const bigint &a,const bigint &b) {
			return b.isZero()?a:gcd(b,a%b);
		}
		static bigint lcm(const bigint &a,const bigint &b) {
			return a/gcd(a,b)*b;
		}
		void from_string(const string &s) {
			sign=1;
			a.clear();
			int pos=0;
			while (pos<(int) s.size() && (s[pos]=='-' || s[pos]=='+')) {
				if (s[pos]=='-')
					sign=-sign;
				++pos;
			}
			for (int i=s.size()-1;i>=pos;i-=__BASE_DIGITS) {
				int x=0;
				for (int j=max(pos,i-__BASE_DIGITS+1);j<=i;j++)
					x=x*10+s[j]-'0';
				a.push_back(x);
			}
			trim();
		}
		friend istream& operator>>(istream &stream,bigint &v) {
			string s;
			stream>>s;
			v.from_string(s);
			return stream;
		}
		friend ostream& operator<<(ostream &stream,const bigint &v) {
			if (v.sign==-1) stream<<'-';
			stream<<(v.a.empty()?0:v.a.back());
			for (int i=(int) v.a.size()-2;i>=0;--i)
				stream<<setw(__BASE_DIGITS)<<setfill('0')<<v.a[i];
			return stream;
		}
};
int main()
{
    scanf("%d",&n);
    memset(f,-1,sizeof(f));
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
		{
            scanf("%1d",&x);
            if(x==1) 
				f[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    f[i][i]=0;
    for(int k=1;k<=n;k++)
	{
        for(int i=1;i<=n;i++)
		{
            if(f[i][k]==-1) 
			continue;
            for(int j=1;j<=n;j++)
			{
                if(f[k][j]==-1) 
					continue;
                if(f[i][j]==-1||f[i][j]>f[i][k]+f[k][j])
                	f[i][j]=f[i][k]+f[k][j];
            }
        }
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    	scanf("%d",&a[i]);
    k[ans=1]=a[1];
    for(int i=1,j;i<m;i=j)
	{
        for(j=i+1;j<=m&&f[a[i]][a[j]]==j-i;j++);
        j--;
        k[++ans]=a[j];
    }
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)
   		printf("%d ",k[i]);
   	return 0;
}