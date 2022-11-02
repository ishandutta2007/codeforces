const
  eps=1e-5;

var
  tmp2,i,j,n,t1,t2,k,x,y:longint;
  tmp1,q1,q2:extended;
  t:array[0..500500]of extended;
  nom:array[0..500500]of longint;

begin
  read(n,t1,t2,k);
  for i:=1 to n do begin
    read(x,y);
    q1:=(x*t1)*(100-k)/100+y*t2;
    q2:=(y*t1)*(100-k)/100+x*t2;
    if (q1>q2)then t[i]:=q1 else t[i]:=q2;
    nom[i]:=i;
  end;
  for i:=1 to n-1 do 
    for j:=1 to n-1 do 
      if (t[j]<t[j+1])or(abs(t[j]-t[j+1])<eps)and(nom[j]>nom[j+1])then begin
        tmp1:=t[j];t[j]:=t[j+1];t[j+1]:=tmp1;
        tmp2:=nom[j];nom[j]:=nom[j+1];nom[j+1]:=tmp2;
      end;
  for i:=1 to n do writeln(nom[i],' ',t[i]:0:2);      
end.