def gcd(a, b) :
    return a if b == 0 else gcd(b, a % b)
n = input()
f = map(int, raw_input().split())
lcm = 1
mx = 1
for i in range(n) :
   a = []
   j = i + 1
   while a.count(j) == 0 :
       #print "j=", j
       a.append(j)
       j = f[j - 1]
   for k in range(len(a)) :
       if a[k] == j :
           idx = k
           break
   #print len(a), idx 
   mx = max(mx, idx)
   lcm = lcm / gcd(lcm, len(a) - idx) * (len(a) - idx)
  # print "lcm = ", lcm
print (mx + lcm - 1) / lcm * lcm