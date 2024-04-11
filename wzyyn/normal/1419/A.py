T=int(input())
for Tid in range(T):
    n=int(input())
    s=input()
    f1,f2=0,0
    for i in range(n):
        if ((i+n) % 2 == 1):
            if (int(s[i]) % 2 == 1):
                f1=1
            else:
                f2=1
    if (n % 2 == 0):
        if f2:
            print(2)
        else:
            print(1)
    else:
        if f1:
            print(1)
        else:
            print(2)