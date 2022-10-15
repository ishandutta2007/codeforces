#import<ios>
int b,r,y;main(){scanf("%d%d%d",&y,&b,&r),--r,++y;printf("%d",3*(r<b?r<y?r:y:b<y?b:y));}