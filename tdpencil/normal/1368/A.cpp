#include<ios>
int a,b,n,t,c;main(){for(scanf("%d",&t);t--;printf("%d\n",c))for(scanf("%d%d%d",&a,&b,&n),c=0;std::max(a,b)<=n;c++)a>b?b+=a:a+=b;}