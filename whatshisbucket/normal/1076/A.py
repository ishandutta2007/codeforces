n=int(input())
a=input()
done=False
for i in range(n-1):
    if a[i]>a[i+1]:
        print(a[0:i]+a[i+1:n])
        done=True
        break
if not done:
    print(a[:-1])