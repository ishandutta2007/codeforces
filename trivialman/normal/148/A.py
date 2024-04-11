k,l,m,n,d=map(int,[input(),input(),input(),input(),input()])
print(d-len([i for i in range(d+1)if(i%k)and(i%l)and(i%m)and(i%n)]))