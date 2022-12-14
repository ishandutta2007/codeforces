import std.stdio;

void main(string[]args){
   long l,r;scanf("%d %d",&l,&r);
   long a=1;int ans=0;
   for(int i=0;i<32;++i){
      long b=a;
      for(int j=0;j<30;++j){
         if(l<=b&&b<=r)++ans;
         b*=3;if(b>r)break;
      }
      a*=2;if(a>r)break;
   }
   printf("%d",ans);
}