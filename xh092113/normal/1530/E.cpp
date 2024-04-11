#include<bits/stdc++.h>



using namespace std;



#define rg register

#define In inline

#define ll long long

#define rep(i,l,r) for(rg int i = (l);i <= (r);i++)

#define dwn(i,r,l) for(rg int i = (r);i >= (l);i--)

#define mp make_pair

#define pb push_back

#define fi first

#define se second



namespace IO{

/*	In char gc(){

		static char buf[100000],*p1 = buf,*p2 = buf;

		if(p1 == p2)p2 = buf + fread(p1 = buf,1,100000,stdin);

		return p1 == p2 ? EOF : *p1++;

	}*/

	In ll read(){

		ll s = 0,ww = 1;

		char ch = getchar();

		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}

		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}

		return s * ww;

	}

	In void write(ll x){

		if(x < 0)putchar('-'),x = -x;

		if(x > 9)write(x / 10);

		putchar('0' + x % 10);

	}

};

using namespace IO;

const int N = 1e5;



template<typename T> void chkmin(T &x,T y){if(y < x)x = y;}

template<typename T> void chkmax(T &x,T y){if(y > x)x = y;}


char s[N+5];
int n,a[N+5],b[N+5],aa[N+5];
int num[26+5];
multiset<int> st;

In int getnext(int cnt){
	while(b[cnt] != -1)cnt++;
	return cnt;
}
void solve(){
	scanf("%s",s + 1);
	n = strlen(s + 1);
	rep(i,1,n)a[i] = s[i] - 'a';
	memset(num,0,sizeof(num));
	rep(i,1,n)num[a[i]]++;	
	memset(b,-1,sizeof(b));
	int minnum = n;rep(i,0,25)if(num[i])chkmin(minnum,num[i]);
	if(minnum == 1){ // ans = 0;
		int c;rep(i,0,25)if(num[i] == 1){c = i;break;}
		int cnt;b[cnt=1] = c;
		rep(i,1,n)if(a[i] != c)b[++cnt] = a[i];
		sort(b + 2,b + cnt + 1);
		rep(i,1,n)putchar('a'+b[i]);putchar('\n');
		return;
	}
	if(minnum == n){ // ans = n - 1
		rep(i,1,n)putchar(s[i]);putchar('\n');	
		return;
	}
	else{ // ans = 1;
		int p,q;
		rep(i,0,25)if(num[i]){p = i;break;}
		rep(i,p + 1,25)if(num[i]){q = i;break;}
//cout<<p<<" "<<q<<endl;
		if(num[p] >= 2 && num[p] - 2 <= (n - 2) / 2){ // begin with pp
			b[1] = b[2] = p;
			for(rg int x = 2,i = 2;i <= num[p];i++,x += 2)b[x] = p;
			int cnt = 1,top = 0;
			rep(i,1,n)if(a[i] != p)aa[++top] = a[i];
			sort(aa + 1,aa + top + 1);
			rep(i,1,top){
				cnt = getnext(cnt);
				b[cnt] = aa[i];
			}
			rep(i,1,n)putchar('a'+b[i]);putchar('\n');
		}
		else{ // begin with pq
			if(num[p] + num[q] == n){
				b[1] = p;
				rep(i,1,num[q])b[i+1] = q;
				rep(i,num[q] + 2,n)b[i] = p;
				rep(i,1,n)putchar('a'+b[i]);putchar('\n');
			}
			else{
				int r;
				rep(i,q + 1,25)if(num[i]){r = i;break;}
				int cnt = 2;b[1] = p,b[2] = q;
				rep(i,2,num[p])b[++cnt] = p;
				b[++cnt] = r;
				st.clear();rep(i,1,num[r] - 1)st.insert(r);
				rep(i,1,n)if(a[i] != p && a[i] != q && a[i] != r)st.insert(a[i]);
				rep(i,1,num[q] - 1)st.insert(q);
				for(int x : st)b[++cnt] = x;
				rep(i,1,n)putchar('a'+b[i]);putchar('\n');
			}
		}
	}
}


int main(){

//	freopen("E.in","r",stdin);
//	freopen("E.out","w",stdout);

	int Tc = read();while(Tc--)solve();
	return 0;

}