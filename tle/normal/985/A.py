n=int(raw_input())
s=map(int,raw_input().split(' '))
s.sort()
ans=2333333333333333333333
for t in range(1,3):
    su=0
    for p in range(0,n/2):
        su+=abs(s[p]-p*2-t)
    ans=min(ans,su)
print ans