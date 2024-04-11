n = int(raw_input())
l = [int(x) for x in raw_input().split()]
print "Yes" if n%2==1 and l[0]%2 == 1 and l[n-1]%2 == 1 else "No"