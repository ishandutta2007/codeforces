n=int(raw_input())
m=[int(k) for k in raw_input().split(" ")]
r=[int(k) for k in raw_input().split(" ")]
mx=720720
isok=[0]*mx
for d in range(mx):
    for i in range(n):
        if (1+d)%m[i]==r[i]:
            isok[d]=1.0
            break
print sum(isok)/mx