n=int(input())
print(4*sum(i*(n//i-1) for i in range(2,n)))