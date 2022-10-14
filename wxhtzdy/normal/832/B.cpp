#include <bits/stdc++.h>
using namespace std;
char u[30],a[100005],w[100005];
int useless[30];
int main() {
  scanf("%s%s",&u,&a);
  for(int i=0;i<27;i++) useless[i]=0;
  for(int i=0;i<strlen(u);i++) useless[(int)u[i]-'a']=1;
  int q;
  scanf("%i",&q);
  int n=strlen(a),pos=-1;
  for(int i=0;i<n;i++) if(a[i]=='*') pos=i;
  for(int QQ=0;QQ<q;QQ++){
    scanf("%s",&w);
    int nl=strlen(w);
    if (pos==-1) {
      if(nl!=n) {printf("NO\n");continue;}
      bool ok=1;
      for(int i=0;i<n;i++) if((a[i]=='?'&&useless[(int)w[i]-'a']==0)||(a[i]!='?'&&a[i]!=w[i]))ok=0;
      if(ok==1)printf("YES\n");
      else printf("NO\n");
    } else {
      if(nl<n-1) {printf("NO\n");continue;}
      if(nl==0&&n==1) {printf("YES\n");continue;}
      bool ok=1;
      int po=n;
      if(nl>n)po=nl;
      for(int i=0;i<pos;i++) if((a[i]=='?'&&useless[(int)w[i]-'a']==0)||(a[i]!='?'&&a[i]!=w[i]))ok=0;
      for(int i=pos+1;i<n;i++) if((a[i]=='?'&&useless[w[nl-(n-i)]-'a']==0)||(a[i]!='?'&&a[i]!=w[nl-(n-i)]))ok=0;
      for(int i=pos;i<pos+(nl-n)+1;i++) if(useless[(int)w[i]-'a']==1)ok=0;
      if(ok==1)printf("YES\n");
      else printf("NO\n");
    }
  }
}