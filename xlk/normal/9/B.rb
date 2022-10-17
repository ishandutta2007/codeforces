n,vb,vs=gets.split.map &:to_i;z=[1e9,1e9,0];
a=gets.split.map &:to_f;x,y=gets.split.map &:to_i
1.upto(n-1){|i|d=((x-a[i])**2+y**2)**0.5;z=[[d/vs+a[i]/vb,d,i],z].min}
p z[2]+1