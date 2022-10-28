b=int(input())
a=input()
done=0
for i in range(len(a)-1):
    if not a[i]==a[i+1]:
        print("YES")
        print(a[i]+a[i+1])
        done=1
        break
if done==0:
    print("NO")