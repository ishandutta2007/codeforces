n=int(input())
check=n-n%2+1
while True:
    done=True
    for guy in range(2,int(check**0.5+1)):
        if check%guy==0:
            check+=2
            done=False
            break
    if done:
        break
extra=check-n
print(check)
for i in range(n-1):
    print(i+1,i+2)
print(n,1)
for i in range(extra):
    print(i+1,i+n//2+1)