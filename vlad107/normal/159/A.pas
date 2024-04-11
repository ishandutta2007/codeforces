{$r-,q-,s-,i-,o+}
const
  MAXN=2222;

var
  a,b,ca,cb:array[0..MAXN]of ansistring;
  c:array[0..MAXN]of longint;
  friends:array[0..MAXN]of boolean;
  s:ansistring;
  d,n,i,j,kol:longint;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  readln(n,d);
  for i:=1 to n do begin
    readln(s);
    a[i]:=copy(s,1,pos(' ',s)-1);
    delete(s,1,pos(' ',s));
    b[i]:=copy(s,1,pos(' ',s)-1);
    delete(s,1,pos(' ',s));
    val(s,c[i]);
  end;
  
  fillchar(friends,sizeof(friends),false);
  for i:=1 to n do 
    for j:=i+1 to n do 
      if (a[i]=b[j])and(b[i]=a[j])and(c[j]-c[i]<=d)and(c[j]-c[i]>0)then friends[i]:=true;
  kol:=0;
  for i:=1 to n do begin
    if (not friends[i])then continue;
    inc(kol);
    ca[kol]:=a[i];
    cb[kol]:=b[i];
    for j:=1 to i-1 do 
      if (friends[j])and(((a[i]=a[j])and(b[i]=b[j]))or((a[i]=b[j])and(b[i]=a[j])))
        then begin
          dec(kol);
          break;
        end;
  end;
  writeln(kol);
  for i:=1 to kol do writeln(ca[i],' ',cb[i]);
  close(output);close(input);
end.