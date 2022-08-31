sn,sk = input().split(' ')
n =int(sn)
k=int(sk)
s=input()
# print(s[0])
# exit(0)
mx=0
l=0
while(l<n):
    if s[l] != 'N':
        l+=1
    else:
        r=l+1
        while((r<n) and (s[r]=='N')):
            r+=1
        mx=max(mx,r-l)
        l=r
if(mx>k):
    print('NO')
    exit(0)
ans = 'NO'
for l in range(n):
    can = 1
    if (l+k < n) and (s[l+k]=='N'):
        can =0
    if(l==0 or s[l-1]!='N'):
        if(l+k<=n):
            for i in range(k):
                if s[l+i]=='Y' :
                    can=0
        else:
            can = 0
    else:
        can = 0
    if can ==1:
        ans = 'YES';
print(ans)