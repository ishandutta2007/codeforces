process.stdin.resume();
process.stdin.setEncoding('utf8');

var input = ``;

function cacheInput(data) {
  input += data;
}

function main() {
    let lines = input.split('\n');
    let t = parseInt(lines[0]);
    for(let _t = 0; _t < t; ++_t) {
        let [n, k] = lines[2*_t+1].split(' ').map(s => parseInt(s))
        let xArray = lines[2*_t+2].split(' ').map(s => parseInt(s))
        
        let [res, dist] = [undefined, 1e9]
        for(let i = k; i < n; ++i) {
            let tmp = Math.ceil((xArray[i] - xArray[i-k])/2)
            if(dist > tmp) [res, dist] = [Math.floor((xArray[i] + xArray[i-k])/2), tmp]
        }
        
        console.log(res)
  }
}

process.stdin.on('data', cacheInput).on('end', main);