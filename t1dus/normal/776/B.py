def isprime(n):
    d = 3
    if n == 2:
        return True
    if n%2 == 0:
        return False
    while d*d <= n:
        if n%d == 0:
            return False
        d += 2    
    return True        
n = int(input())
if n == 1:
    print(1)
    print(1)
elif n == 2:
    print(1)
    print(1,1)
else:
    print(2)
    for i in range(2,n+2):
        if isprime(i):
            print(1,end = ' ')
        else:
            print(2,end = ' ')
    print('')