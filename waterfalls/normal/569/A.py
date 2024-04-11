T,S,q = map(int,input().split())
ans = 0
while S<T:
    ans+=1
    S*=q
print(ans)