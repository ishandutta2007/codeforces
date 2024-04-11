s,t=raw_input(),raw_input()
n,m=len(s),len(t)
s='$'*m+s+'$'*m
print min(sum(1 for a,b in zip(s[i:i+m],t)if a!=b)for i in range(m+n))