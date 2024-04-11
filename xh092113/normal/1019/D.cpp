#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define rg register
#define In inline

const ld eps = 1e-9;
const int N = 2000;

In int read(){
	int s = 0,ww = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
	while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
	return s * ww;
}

In void write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)write(x / 10);
	putchar('0' + x % 10);
}

In int sgn(ld x){return x < -eps ? -1 : x > eps;}

In ld sqr(ld x){return x * x;}

struct vec{
	ld x,y;
	vec(){}
	vec(ld _x,ld _y){x = _x,y = _y;}
	In friend vec operator + (vec a,vec b){
		return vec(a.x + b.x,a.y + b.y);
	}
	In friend vec operator - (vec a,vec b){
		return vec(a.x - b.x,a.y - b.y);
	}
	In friend vec operator * (vec a,ld k){
		return vec(a.x * k,a.y * k);
	}
	In friend vec operator / (vec a,ld k){
		return vec(a.x / k,a.y / k);
	}
	In friend ld Cross(vec a,vec b){
		return a.x * b.y - a.y * b.x;
	}
	In friend ld Dot(vec a,vec b){
		return a.x * b.x + a.y * b.y;
	}
	In friend bool InUpper(vec a){
		int k;
		return ((k=sgn(a.y)) > 0 || (k==0&&sgn(a.x)>0)); 
	}
	In friend ld len(vec a){
		return sqrt(sqr(a.x) + sqr(a.y));
	}
	In friend vec Rot90(vec a){
		return vec(a.y,-a.x);
	}
};

struct seg{
	vec A,B;
	seg(){}
	seg(vec _A,vec _B){A = _A,B = _B;}
	In friend ld len(seg a){
		return len(a.B - a.A);
	}
};

vec Upward(vec p,ld d,vec v){
	ld Len = len(v);
	return p + v * d / Len;
}

In ld dis(vec p,seg a){
	return Cross(a.B - p,a.A - p) / len(a);
}

pair<int,int>pr[N*N+5];
vec p[N+5],s[N+5];
int rk[N+5];
ld S;
int n;

In bool cmp1(pair<int,int>i,pair<int,int>j){
	seg a = seg(p[i.first],p[i.second]),b = seg(p[j.first],p[j.second]);
	int k1 = InUpper(a.B-a.A),k2 = InUpper(b.B-b.A);
	if(k1 != k2)return k1 < k2;
	return sgn(Cross(a.B-a.A,b.B-b.A)) > 0;
}

In bool cmp2(vec a,vec b){
	int k;
	if((k=sgn(a.y-b.y)) != 0)return k > 0;
	return sgn(a.x - b.x) > 0;
}

seg curp;

In bool cmp3(vec a,vec b){
	return dis(a,curp) > dis(b,curp);
}

void PrAns(vec a,vec b,vec c){
	puts("Yes");
	write((int)round(a.x)),putchar(' '),write((int)round(a.y)),putchar('\n');
	write((int)round(b.x)),putchar(' '),write((int)round(b.y)),putchar('\n');
	write((int)round(c.x)),putchar(' '),write((int)round(c.y)),putchar('\n');
}

int main(){
//	freopen("CF1019D.in","r",stdin);
//	freopen("CF1019D.out","w",stdout);
	n = read();cin>>S;//scanf("%llf",&S);
	for(rg int i = 1;i <= n;i++){
		int x = read(),y = read();
		p[i] = vec(x,y);
	}
	sort(p + 1,p + n + 1,cmp2);
//for(rg int i = 1;i <= n;i++)cout<<p[i].x<<" "<<p[i].y<<endl;
//cout<<endl;
	for(rg int i = 1;i <= n;i++)rk[i] = i,s[i] = p[i];
	int cnt = 0;
	for(rg int i = 1;i <= n;i++)
		for(rg int j = 1;j <= n;j++){
			if(i == j || InUpper(p[j]-p[i]))continue;
			pr[++cnt] = make_pair(i,j);
		}
	sort(pr + 1,pr + cnt + 1,cmp1);
//cout<<"pr[]:"<<endl;
//for(rg int i = 1;i <= cnt;i++)cout<<"i="<<i<<" "<<pr[i].first<<" "<<pr[i].second<<endl;
//cout<<endl;
	for(rg int k = 1;k <= cnt;k++){
//cout<<"k="<<k<<endl;
		int i = pr[k].first,j = pr[k].second;
		curp = seg(p[i],p[j]);
		swap(s[rk[i]],s[rk[j]]);
		swap(rk[i],rk[j]);
		ld h = 2 * S / len(curp.B - curp.A);
//cout<<"s[]:"<<endl;
//for(rg int t = 1;t <= n;t++)cout<<"t="<<t<<" "<<s[t].x<<" "<<s[t].y<<endl;
//cout<<"rk[]:"<<endl;
//for(rg int t = 1;t <= n;t++)cout<<"t="<<t<<" "<<rk[t]<<endl;
		int pos = lower_bound(s + 1,s + n + 1,Upward(curp.A,h,Rot90(curp.B-curp.A)),cmp3) - s;
//cout<<"pos="<<pos<<endl;
		if(sgn(fabs(dis(s[pos],curp))-h) == 0){
			PrAns(s[pos],p[i],p[j]);
			return 0;
		}
		pos = lower_bound(s + 1,s + n + 1,Upward(curp.A,-h,Rot90(curp.B-curp.A)),cmp3) - s;
		if(sgn(fabs(dis(s[pos],curp))-h) == 0){
			PrAns(s[pos],p[i],p[j]);
			return 0;
		}
	}
	puts("No");
	return 0;
}