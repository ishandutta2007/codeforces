#include<cstring>
#include<cstdio>
int len, l1;
char st[222222];
int main()
{
    scanf("%s", st);
    len = strlen(st);
    for(int i = 0; i < len; i++)
    {
        if(st[i] == st[i + 1] and st[i + 1] == st[i + 2])
        {
            st[i] = 'X';
        }
    }
    l1 = 0;
    for(int i = 0; i < len; i++) if(st[i] != 'X') st[l1++] = st[i];
    len = l1;
    st[len] = 0;
    st[len + 1] = 1;
    for(int i = 0; i < len; i++)
    {
        if(st[i] == st[i + 1] and st[i + 2] == st[i + 3])
        {
            st[i += 3] = 'X';
        }
    }
    for(int i = 0; i < len; i++) if(st[i] != 'X') printf("%c", st[i]); printf("\n");
}