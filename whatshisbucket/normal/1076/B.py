n=int(input())
if n%2==0:
    print(n//2)
else:
    mini=0
    for i in range(3,int(n**0.5)+1):
        if n%i==0:
            mini=i
            break
    if mini==0:
        print(1)
    else:   
        print((n-mini)//2+1)