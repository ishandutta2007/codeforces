var n=+readline()
var st=[]
while(n-->0){
   hm=readline().split(':')
   st.push(hm[0]*60+ +hm[1])
}
st.sort((a,b)=>a-b)

var ans=0
for(var i=1;i<st.length;++i){
   ans=Math.max(ans,st[i]-st[i-1])
}
ans=Math.max(ans,st[0]+24*60-st[st.length-1])-1

var h=Math.floor(ans/60)+'',m=(ans%60)+'';
while(h.length<2)h='0'+h;
while(m.length<2)m='0'+m;
print(h+':'+m)