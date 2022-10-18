#include<bits/stdc++.h>

#define len first
#define cs second
#define c1 first
#define c2 second
#define mp make_pair
#define it iterator

using namespace std;

typedef pair< char , char > pcc;
typedef pair< int , pcc > pic;
typedef multiset< pic > sp;

int main()
{
    int n;
    scanf("%d",&n);
    sp ss;
    for(int i=0;i<n;i++)
    {
        char c[1001];
        scanf("%s",&c);
        string s(c);
        int l=s.length();
        char c1='\0',c2='\0';
        bool ok=true;
        for(int j=0;j<l;j++)
            if(c1!=s[j]&&c2!=s[j])
                if(c1=='\0')
                    c1=s[j];
                else
                    if(c2=='\0')
                        c2=s[j];
                    else
                    {
                        ok=false;
                        break;
                    }
        if(c2=='\0')
            c2=c1;
        if(c1>c2)
            swap(c1,c2);
        if(ok)
            ss.insert(mp(l,mp(c1,c2)));
        //printf("%s - %d , %s: %c %c\n",c,l,ok?"ok":"no",c1,c2);
    }
    n=ss.size();
    int m=0;
    for(int i=0;i<26;i++)
        for(int j=i;j<26;j++)
        {
            int sum=0;
            for(sp::it k=ss.begin();k!=ss.end();k++)
                if((k->cs==mp((char)('a'+i),(char)('a'+j)))||
                   (k->cs==mp((char)('a'+i),(char)('a'+i)))||
                   (k->cs==mp((char)('a'+j),(char)('a'+j))))
                    sum+=k->len;
            m=max(m,sum);
        }
    printf("%d\n",m);
}