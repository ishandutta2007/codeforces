import array

def isprime(x):
    for i in range(2,x-1):
        if x%i==0:
            return 0
    return 1

T=int(input())
for Tid in range(T):
    n=int(input())
    x=-1
    for i in range(2,100):
        if isprime(i)==0:
            if isprime(i+n-1)==1:
                x=i
    for i in range(n):
        for j in range(n):
            if i==j:
                print(x,end=' ')
            else:
                print(1,end=' ')
        print()