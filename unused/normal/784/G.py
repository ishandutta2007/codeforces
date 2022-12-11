n=str(eval(raw_input()))
print '+'*ord('0')
for c in n:
    diff = ord(c) - ord('0')
    print '+'*diff+'.'+'-'*diff