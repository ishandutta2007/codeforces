n = int(input())
a = [int(x) for x in input().split()]
cnt = [0]*100013
for i in a:
    cnt[i]+=1
need = []
for i in range(1,n+1):
    if cnt[i]==0:
        need.append(i)
on = 0
for i in a:
    if i>n:
        print(need[on])
        on+=1
    else:
        if cnt[i]>1:
            print(need[on])
            on+=1
            cnt[i]-=1
        else:
            print(i)