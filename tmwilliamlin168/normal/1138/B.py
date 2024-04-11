n=int(input())
a=input()
b=input()
init=sum(int(c) for c in b)
mp=[[] for i in range(3)]
for i in range(n):
    c=int(a[i])+int(b[i])
    mp[c]+=[i+1]
need=n//2
for i in range(len(mp[1])+1):
    for j in range(len(mp[2])+1):
        if i+2*j==init and i+j<=need and i+j+len(mp[0])>=need:
            print(*(mp[0][:need-i-j]+mp[1][:i]+mp[2][:j]))
            exit()
print(-1)