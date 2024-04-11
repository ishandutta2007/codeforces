    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define ld long double
    #define For(i,x,y)	for(ll i=(x);i<=(y);++i)
    #define FOr(i,x,y)	for(ll i=(x);i>=(y);--i)
    #define rep(i,x,y)	for(ll i=(x);i<(y);++i)
    #define clr(a,v)	memset(a,v,sizeof(a))
    #define cpy(a,b)	memcpy(a,b,sizeof(a))
    #define fi	first
    #define se	second
    #define	pb	push_back
    #define mk	make_pair
    #define pa	pair<ll,ll>
    #define y1	y11111111111111
    #define debug	puts("@@@@@@@@@@@@@@@@@@@@@@@")
    ll read(){
    	ll x=0,f=1;	char ch=getchar();
    	for(;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
    	for(;ch>='0'&&ch<='9';ch=getchar())	x=x*10+ch-'0';
    	return x*f;
    }
    void write(ll x){
    	if (x<0)	putchar('-'),write(-x);
    	else{
    		if (x>=10)	write(x/10);
    		putchar(x%10+'0');
    	}
    }
    const ll N=300010;
    vector<pa>Ans;
    ll g[4][N],up[N],a[N],top[14],ls,lss,n;
    int main(){
    	n=read();
    	For(i,1,n)a[i]=read();
    	ll ls=n;
    	FOr(i,n,1){
    		if (a[i]==0)continue;
    		if (a[i]==1){
    			Ans.pb(mk(i,i));
    			g[1][++top[1]]=i;
    				up[i]=i;
    		}
    		if (a[i]==2){
    			if (top[1]){
    				Ans.pb(mk(i,up[g[1][top[1]]]));
    				up[i]=up[g[1][top[1]]];
    				--top[1];
    				g[2][++top[2]]=i;
    			}else{
    				puts("-1");return 0;
    			}
    		}
    		if (a[i]==3){
    			if (top[3]){
    				Ans.pb(mk(i,i));
    				Ans.pb(mk(g[3][top[3]],i));
    				--top[3];
    				++top[3];
    				g[3][++top[3]]=i;
    			}else
    			if (top[2]){
    				Ans.pb(mk(i,i));
    				Ans.pb(mk(g[2][top[2]],i));
    				--top[2];
    				++top[3];
    				g[3][++top[3]]=i;
    			}else
    			if (top[1]){
    				Ans.pb(mk(i,i));
    				Ans.pb(mk(g[1][top[1]],i));
    				--top[1];
    				++top[3];
    				g[3][++top[3]]=i;
    			}else{
    				puts("-1");return 0;
    			}
    		}
    	}
    	cout<<Ans.size()<<endl;
    	rep(i,0,Ans.size())cout<<Ans[i].se<<' '<<Ans[i].fi<<endl;
    }