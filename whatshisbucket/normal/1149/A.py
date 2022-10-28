n=int(input())
a=input().split()
ones=a.count("1")
twos=n-ones
if ones==0 or twos==0:
    print(" ".join(a))
else:
    print("2 1"+" 2"*(twos-1)+" 1"*(ones-1))