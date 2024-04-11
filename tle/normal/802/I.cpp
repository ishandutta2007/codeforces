#include<bits/stdc++.h>
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
const int N=201234;
char ch[N];
int n,last=1,cnt=1,a[N][26],mx[N],fa[N],T[N],Seq[N],f[N],w[N];
void extend(int c){
    int p=last,np=last=++cnt;
    mx[np]=mx[p]+1;
	f[np]=w[np]=1;
    while(!a[p][c]&&p)a[p][c]=np,p=fa[p];
    if(!p)fa[np]=1;
    else{
        int q=a[p][c];
        if(mx[q]==mx[p]+1)fa[np]=q;
        else{
            int nq=++cnt;mx[nq]=mx[p]+1;
            memcpy(a[nq],a[q],sizeof(a[q]));
            fa[nq]=fa[q];
            fa[q]=fa[np]=nq;
            while(a[p][c]==q)a[p][c]=nq,p=fa[p];
        }
    }
}
void get_order(){
    for(int i=1;i<=cnt;i++) T[mx[i]]++;
    for(int i=1;i<=n;i++) T[i]+=T[i-1];
    for(int i=1;i<=cnt;i++) Seq[T[mx[i]]--]=i;
}
ll solve(){
    ll ans=0;
    for(int i=cnt;i>=1;i--) f[fa[Seq[i]]]+=f[Seq[i]];
    for(int i=cnt;i>=1;i--){
        int x=Seq[i];
        ans+=(ll)f[x]*w[fa[x]]*mx[fa[x]];
        w[fa[x]]+=f[x];
    }
    return ans;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		clr(a);clr(f);clr(fa);clr(mx);clr(Seq);clr(::T);clr(w);
		cnt=last=1;
	    scanf("%s",ch);
	    n=strlen(ch);
	    for(int i=n-1;i>=0;i--) extend(ch[i]-'a');
	    ll ans=0;
	    get_order();
	    ans=solve();
	    printf("%I64d\n",ans*2+(ll)n*(n+1)/2);
	}
    return 0;
}