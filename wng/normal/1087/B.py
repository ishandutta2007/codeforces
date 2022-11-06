n,k=[int(k) for k in raw_input().split(" ")]

for i in range(k-1,0,-1):
    if not n%i:
        print (n/i)*k+i
        break