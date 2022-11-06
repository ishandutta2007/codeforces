n=readline();
//print(n);
x=readline().split(' ');
imp=0;
pai=0;
for (i = 0; i < n; i++) { 
    imp+=(x[i]%2)?1:0;
    pai+=(1-x[i]%2)?1:0;
}
print(Math.min(imp,pai)+Math.floor(Math.max(imp-pai,0)/3));