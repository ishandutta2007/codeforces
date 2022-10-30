n = int(input())
has = []
ans = 0
for i in range(n):
    c,x = input().split()
    if c=="+":
        has.append(x)
    else:
        if x in has:
            has.remove(x)
        else:
            ans+=1
    ans = max(ans,len(has))
print(ans)