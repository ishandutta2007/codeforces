#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string cur_dir;

void parse_string()
{
    string dir_name, real_name, tmp="";
    int i, j, st;
    cin >> dir_name;
    if (dir_name[0]=='/')
    {real_name="root"; st=1;}
    else {real_name=cur_dir; st=0;}
    for(i=st; i<(int)dir_name.length(); i++)
    {
        if (dir_name[i]=='/')
        {
            if (tmp=="..")
            {
                for(j=real_name.length()-1; real_name[j]!='/'; j--);
                real_name=real_name.substr(0, j);
            }
            else real_name=real_name+"/"+tmp;
            tmp.clear();
        }
        else tmp.push_back(dir_name[i]);
    }
    if (!tmp.empty())
    {
        if (tmp=="..")
        {
            for(j=real_name.length()-1; real_name[j]!='/'; j--);
            real_name=real_name.substr(0, j);
        }
        else real_name=real_name+"/"+tmp;
        tmp.clear();
    }
    cur_dir=real_name;
    return;
}

void output_dir(string dir_name)
{
    string tmp=dir_name.substr(4, dir_name.length()-1);
    tmp+="/";
    cout << tmp << endl;
}

int main()
{   
    string cmd, dir_name;
    int n, i;
    scanf("%d", &n);
    cur_dir="root";
    for(i=0; i<n; i++)
    {
        cin >> cmd;
        if (cmd=="pwd") output_dir(cur_dir);
        else parse_string();
    }
}