a = int(input())
ans = 0
while a>0:
    if a%8==1:
        ans+=1
    a//=8
print(ans)