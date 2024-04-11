s=set(int((((5**0.5)+1)/2)**i/5**0.5+0.5)for i in range(99))
print ''.join(['oO'[i+1 in s]for i in range(input())])