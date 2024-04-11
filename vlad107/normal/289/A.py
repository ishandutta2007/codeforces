R=lambda:map(int,raw_input().split())
n,k=R()
print (k-sum(map(lambda x:x[1]-x[0]+1,[R()for i in range(n)]))%k)%k