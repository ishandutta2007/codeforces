n=int(input())
guys=list(map(int,input().split()))
maxi=-1
done=0
for i in range(n):
    if guys[i]>maxi+1 and done==0:
        print(i+1)
        done=1
    else:
        maxi=max(maxi,guys[i])
if done==0:
    print(-1)