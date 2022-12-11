#include <iostream>
#include <string>
#include <vector>
using namespace std;
string word[210];
vector <bool> used;// dfs,  
vector <int> mt;//mt[i] -    ,    i     
vector <int> graph[210];//graph[i] -    ,     i  
vector <string> substring;// 
string rez[210];//   
int hash[27][27][27][27];
int n;
void sumbol_code ( string str, int *p )
{
    for ( int i=0; i<str.length(); i++ )
    {
        *p=str[i]-'a';
        p++;
    }
    return;
}
bool search_equal ( string str, int ind )
{
    vector <int> a;
    a.assign(4, 26);
    sumbol_code(str, &a[0]);
    if ( hash[a[0]][a[1]][a[2]][a[3]]==0 )
    {
        graph[ind].push_back(substring.size());
        hash[a[0]][a[1]][a[2]][a[3]]=substring.size()+1;
    }
    else
    {
        graph[ind].push_back(hash[a[0]][a[1]][a[2]][a[3]]-1);
        return false;
    }
    return true;
}//, ,             
void podposl ( string str, int k, int ind, string isk, int ind_stroki )
{
    if ( isk.length()<=k&&isk.length()>0 )
    {
        if ( search_equal(isk, ind_stroki) )
            substring.push_back(isk);
    }
    for ( int i=ind; i<str.length(); i++ )
        podposl(str, k, i+1, isk+str[i], ind_stroki);
    return;
}//,    
void make_substring ( string str, int ind )
{
    podposl(str, 4, 0, "", ind);
}//  
bool smart_dfs ( int vertex )
{
    if ( used[vertex] )
        return false;
    used[vertex]=true;
    for ( int i=0; i<graph[vertex].size(); i++ )
    {
        int to=graph[vertex][i];
        if ( mt[to]==-1||smart_dfs(mt[to]) )
        {
            mt[to]=vertex;
            return true;
        }
    }
    return false;
}   
bool it_all ()
{
    int all=0;
    for ( int i=0; i<mt.size(); i++ )
    {
        if ( all==n )
            break;
        if ( mt[i]!=-1 )
        {
            rez[mt[i]]=substring[i];
            all++;
        }
    }
    if ( all==n )
        return true;
    return false;
}
int main()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout); 
    cin >> n;
    for ( int i=0; i<n; i++ )
    {
        cin >> word[i];
        make_substring(word[i], i);
    }
    mt.assign(substring.size(), -1);
    for ( int i=0; i<n; i++ )
    {
        used.assign(n, false);
        smart_dfs(i);
    }
    if ( it_all() )
    {
        for ( int i=0; i<n; i++ )
            cout << rez[i] << '\n';
    }
    else
        cout << -1;
    return 0;
}