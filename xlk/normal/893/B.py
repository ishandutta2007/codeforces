n=input()
print max(2**i-1<<i-1 for i in range(1,99)if n%(2**i-1<<i-1)==0)