s=[raw_input()for i in range(4)]
if sum([((s[i][j]=='#')+(s[i+1][j]=='#')+(s[i][j+1]=='#')+(s[i+1][j+1]=='#')!=2) for i in range(3) for j in range(3)])>0:
    print "YES"
else: print "NO"