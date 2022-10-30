n,k = map(int,input().split())
nums = [int(x) for x in input().split()]
zero = {}
one = {}
ans = 0
for i in range(n):
    x = nums[i]
    if x%k==0:
        if x//k in one:
            ans+=one[x//k]
        if x//k in zero:
            if x not in one:
                one[x] = 0
            one[x]+=zero[x//k]
    if x not in zero:
        zero[x] = 0
    zero[x]+=1
print(ans)