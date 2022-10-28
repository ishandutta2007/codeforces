import sys
 
input_words = sys.stdin.read().split()
input_it = 0
 
def read_word():
    global input_it
    input_it += 1
    return input_words[input_it - 1]
 
output_words = []
 
def print_word(x):
    global output_words
    output_words.append(str(x))
    
t=int(read_word())
for _ in range(t):
    n=int(read_word())
    g=[]
    cnt=0
    for i in range(n):
        s=[int(c) for c in read_word().strip()]
        cnt+=s.count(1)
        g.append(s+s.copy())
    for i in range(n):
        g.append(g[i].copy())
    for i in range(1, 2*n):
        for j in range(1, 2*n):
            g[i][j]+=g[i-1][j-1]
    ans=69696969
    for i in range(0, n):
        for j in range(0, n):
            x=g[i+n][j+n]-g[i][j]
            ans=min(ans, n-x+(cnt-x))
    print_word(ans)
    
print('\n'.join(output_words))