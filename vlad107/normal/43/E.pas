{$r-,q-,s-,i-,o+}
var
  res,n,s,i,j,qi,qj,si,sj,p,q:longint;
  nt,v,t:array[0..111,0..111]of longint;
  kg:array[0..111]of longint;

begin
  read(n,s);
  for i:=1 to n do begin
    read(kg[i]);
    for j:=1 to kg[i] do read(v[i][j],t[i][j]);
    for j:=1 to kg[i] do nt[i][j]:=t[i][j];
  end;
  res:=0;
  for i:=1 to n do 
    for j:=i+1 to n do begin
      qi:=1;qj:=1;
      si:=0;sj:=0;
      p:=-1;
      for q:=1 to kg[i]do t[i][q]:=nt[i][q];
      for q:=1 to kg[j]do t[j][q]:=nt[j][q];
      for q:=1 to kg[i]+kg[j] do begin
        if (t[i][qi]<t[j][qj])then begin
          si:=si+t[i][qi]*v[i][qi];
          sj:=sj+t[i][qi]*v[j][qj];
          if ((p=1)and(si<sj))or
             ((p=0)and(si>sj))then inc(res);
          if (si<sj)then p:=0 else
          if (si>sj)then p:=1;
          t[j][qj]:=t[j][qj]-t[i][qi];
          inc(qi);
        end else begin
          si:=si+t[j][qj]*v[i][qi];
          sj:=sj+t[j][qj]*v[j][qj];
          if ((p=1)and(si<sj))or
             ((p=0)and(si>sj))then inc(res);
          if (si<sj)then p:=0 else
          if (si>sj)then p:=1;
          t[i][qi]:=t[i][qi]-t[j][qj];
          inc(qj);
        end;    	
        if (si=s)or(sj=s)then break;
      end;
    end;
  writeln(res);
end.