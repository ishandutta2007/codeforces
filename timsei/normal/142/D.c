char s[105];int n,m,k,a[8],G,R,has,g,r;
#define o(x) return puts((!x)?"First":"Second")*0
#define F(i,a,b) for(int i=a;i<=b;++i)
main(){scanf("%d%d%d",&n,&m,&k);F(i,1,n){has=G=R=0;scanf("%s",s+1);F(j,1,m)if(s[j]=='-')has=1;else if(s[j]=='G')G=j;else if(s[j]=='R')R=j;if((!G&&!R)||!has)continue;if(!G)r=1;else if(!R)g=1;else F(j,0,7)if((1<<j)&(abs(R-G)-1))++a[j];}if(r&&g)return puts("Draw")*0;if(r)o(1);if(g)o(0);F(i,0,7)if(a[i]%(k+1))o(0);o(1);}