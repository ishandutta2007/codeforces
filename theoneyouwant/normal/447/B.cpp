#include<iostream>
#include<map>
using namespace std;

int main()
{
    string s;
    int k,max;
    long long int sum=0;
    cin>>s>>k;
    map<char,int> m;
    int r;
    cin>>r; max = r;
    m['a']=r;
    cin>>r;
    m['b']=r;
    cin>>r;
    m['c']=r;
    cin>>r;
    m['d']=r;
    cin>>r;
    m['e']=r;
    cin>>r;
    m['f']=r;
    cin>>r;
    m['g']=r;
    cin>>r;
    m['h']=r;
    cin>>r;
    m['i']=r;cin>>r;
    m['j']=r;cin>>r;
    m['k']=r;
    cin>>r;
    m['l']=r;
    cin>>r;
    m['m']=r;
    cin>>r;
    m['n']=r;
    cin>>r;
    m['o']=r;
    cin>>r;
    m['p']=r;
    cin>>r;
    m['q']=r;cin>>r;
    m['r']=r;
    cin>>r;
    m['s']=r;
    cin>>r;
    m['t']=r;
    cin>>r;
    m['u']=r;
    cin>>r;
    m['v']=r;
    cin>>r;
    m['w']=r;
    cin>>r;
    m['x']=r;
    cin>>r;
    m['y']=r;
    cin>>r;
    m['z']=r;
    
 
    for(map<char,int>::iterator it = m.begin();it!=m.end();it++)
    {
        if(((*it).second)>max)
        {
            max=((*it).second);
        }
    }
    for(int i=0;i<s.length();i++)
    {
        sum=sum+(i+1)*m[s[i]];
    }
    for(int i=s.length();i<s.length()+k;i++)
    {
        sum = sum + (i+1)*max;
    }
    cout<<sum;
    return 0;
}