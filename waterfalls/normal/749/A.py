n = int(input())
print(n//2)
if n%2==0: print(' '.join(['2']*(n//2)))
else: print(' '.join(['3']+['2']*((n-3)//2)))