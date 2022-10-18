#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    multiset<int> a;
    string s;
    int m=0;
    for(int i=0;i<n;i++)
    {
        char c[12];
        scanf("%s",c);
        int x;
        switch(c[0])
        {
            case 'i':
                scanf("%d",&x);
                m++;
                //cout<<"m++\n";
                s+="insert ";
                //cout<<"insert ";
                sprintf(c,"%d",x);
                //cout<<x;
                s+=c;
                s+="\n";
                //cout<<"\n";
                a.insert(x);
                break;
            case 'g':
                scanf("%d",&x);
                while(!a.empty()&&(*a.begin()<x))
                {
                    m++;
                    //cout<<"m++\n";
                    s+="removeMin\n";
                    //cout<<"removeMin\n";
                    a.erase(a.begin());
                }
                if(a.empty()||(*a.begin()!=x))
                {
                    m++;
                    //cout<<"m++\n";
                    s+="insert ";
                    //cout<<"insert ";
                    sprintf(c,"%d",x);
                    //cout<<x;
                    s+=c;
                    s+="\n";
                    //cout<<"\n";
                    a.insert(x);
                }
                m++;
                //cout<<"m++\n";
                s+="getMin ";
                //cout<<"getMin ";
                sprintf(c,"%d",x);
                //cout<<x;
                s+=c;
                s+="\n";
                //cout<<"\n";
                break;
            case 'r':
                if(a.empty())
                {
                    m++;
                    //cout<<"m++\n";
                    s+="insert ";
                    //cout<<"insert ";
                    sprintf(c,"%d",0);
                    //cout<<0;
                    s+=c;
                    s+="\n";
                    //cout<<"\n";
                    a.insert(0);
                }
                m++;
                //cout<<"m++\n";
                s+="removeMin\n";
                //cout<<"removeMin\n";
                a.erase(a.begin());
                break;
        }
    }
    cout<<m<<endl<<s;
}