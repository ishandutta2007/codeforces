t=[int(k) for k in input().split(" ")][0]

for k in range(t):
    n=[int(k) for k in input().split(" ")][0]
    s=[]
    nb1=0
    isatleastoneimpair=False
    for k in range(n):
        s+=[[int(k) for k in input()]]
        nb1+=sum(s[-1])
        isatleastoneimpair|=len(s[-1])%2
    print(n - (1 if  ((nb1%2) and not isatleastoneimpair) else 0))