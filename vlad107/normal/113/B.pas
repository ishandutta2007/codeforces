
var
  qt,kh,ans,i,j:longint;
  t1,t2,s:ansistring;
  next:array[0..2050100,'a'..'z']of longint;
  ok:array[0..5000]of boolean;

begin
  readln(s);
  readln(t1);
  readln(t2);
  kh:=0;
  for i:=1 to length(s)-length(t2)+1do begin
    j:=i;
    while (j<length(t2)+i)and(s[j]=t2[j-i+1])do inc(j);
    if (j=length(t2)+i)then ok[length(t2)+i-1]:=true;
  end;

  ans:=0;
  for i:=1 to length(s)-length(t1)+1do begin
    j:=i;
    while (j<length(t1)+i)and(s[j]=t1[j-i+1])do inc(j);
    if (j=length(t1)+i)then begin
      qt:=0;
      for j:=i to length(s)do begin
        if (next[qt][s[j]]=0)then begin
          if (ok[j])and(j>=i+length(t1)-1)and(j>=i+length(t2)-1)then inc(ans);
          inc(kh);
          next[qt][s[j]]:=kh;
        end;
        qt:=next[qt][s[j]];
      end;
    end;
  end;  
  writeln(ans);
end.