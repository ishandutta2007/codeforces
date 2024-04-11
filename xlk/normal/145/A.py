c=[i<j for i,j in zip(raw_input(),raw_input()) if i!=j]
print max(sum(c),len(c)-sum(c))