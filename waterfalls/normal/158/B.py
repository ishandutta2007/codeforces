n = int(input())
a = [int(x) for x in input().split()]
cnt = [0]*5
for i in a: cnt[i]+=1
ans = 0

cur = cnt[4]
ans+=cur
cnt[4]-=cur

cur = min(cnt[3],cnt[1])
ans+=cur
cnt[3]-=cur
cnt[1]-=cur

cur = cnt[2]//2
ans+=cur
cnt[2]-=2*cur

cur = min(cnt[2],cnt[1]//2)
ans+=cur
cnt[2]-=cur
cnt[1]-=2*cur

cur = min(cnt[2],cnt[1])
ans+=cur
cnt[2]-=cur
cnt[1]-=cur

cur = (cnt[1]+3)//4
ans+=cur
cnt[1] = 0

print(ans+sum(cnt))