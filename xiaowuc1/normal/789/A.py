n, k = (int(x) for x in raw_input().split())
l = [int(x) for x in raw_input().split()]
l = [(x+k-1)/k for x in l]
print (sum(l)+1)/2