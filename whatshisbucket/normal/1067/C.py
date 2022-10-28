n=int(input())
for i in range(n//3):
    print(2*i,0)
    print(2*i+1,0)
    print(2*i+1,3)
for i in range(n%3):
    print(2*(n//3)+i,0)