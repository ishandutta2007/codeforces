#include<bits/stdc++.h>

using namespace std;

const int inf=2e9;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int s1[n],s2[n];
    s1[0]=a[0]==1;
    s2[0]=a[0]==2;
    //printf("%d : %d , %d\n",0,s1[0],s2[0]);
    for(int i=1;i<n;i++)
        s1[i]=s1[i-1]+(a[i]==1),
        s2[i]=s2[i-1]+(a[i]==2);//,
        //printf("%d : %d , %d\n",i,s1[i],s2[i]);
    map<int,int> m1,m2;
    for(int i=0;i<n;i++)
        m1.insert(make_pair(s1[i],s2[i])),
        m2.insert(make_pair(s2[i],s1[i]));
    set< pair<int,int> > ans;
    for(int t=1;t<=n;t++)
    {
        int c1=0,c2=0,p1=0,p2=0;
        //printf("t = %d :\n",t);
        while(true)
        {
            map<int,int>::iterator it1=m1.find(c1+t);
            int nc2=(it1==m1.end())?2e9:(it1->second);
            map<int,int>::iterator it2=m2.find(c2+t);
            int nc1=(it2==m2.end())?2e9:(it2->second);
            if(nc1==inf&&nc2==inf)break;
            if(nc1<c1+t)
                c1=nc1,c2+=t,p2++;//,printf("nc1<c1+t -> c1=nc1,c2+=t");
            else if(nc2<c2+t)
                c2=nc2,c1+=t,p1++;//,printf("nc2<c2+t -> c2=nc2,c1+=t");
            //else if(nc1==c1+t&&nc2==c2+t)
            //    c1=nc1,c2=nc2,printf("nc1==c1+t&&nc2==c2+t -> c1=nc1,c2=nc2");
            //else
            //    printf("ERROR : t = %d , c1 = %d , c2 = %d , nc1 = %d , nc2 = %d\n",
            //           t,c1,c2,nc1,nc2),exit(0);
            //printf(" : c1 = %d , c2 = %d\n",c1,c2);
        }
        int p=(p1==p2)?0:((p1>p2)?1:2),s=max(p1,p2);
        if(c1==s1[n-1]&&c2==s2[n-1]&&p==a[n-1])
            ans.insert(make_pair(s,t));//,
        //    printf("+ %d %d\n",s,t);
        //else
        //    printf("- %d %d\n",s,t);
    }
    printf("%d\n",ans.size());
    for(set< pair<int,int> >::iterator i=ans.begin();i!=ans.end();i++)
        printf("%d %d\n",i->first,i->second);
}